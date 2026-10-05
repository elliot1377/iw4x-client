#include "ArabicFonts.hpp"
#include "ZoneBuilder.hpp"

namespace Components
{
  Dvar::Var ArabicFonts::LocArabicFonts;

  Game::XAssetHeader ArabicFonts::FindFont([[maybe_unused]] const Game::XAssetType type, const std::string& name)
  {
    Game::XAssetHeader header{ nullptr };

    if (!LocArabicFonts.get<bool>())
    {
      return header;
    }

    // Menus are not consistent about casing, e.g. "fonts/bigfont"
    static constexpr std::string_view prefix = "fonts/";
    const auto lowerName = Utils::String::ToLower(name);
    if (!lowerName.starts_with(prefix) || lowerName.starts_with("fonts/ar_"))
    {
      return header;
    }

    // Font names in the zone keep the stock casing, so match the lookup case-insensitively
    static const std::unordered_map<std::string, std::string> replacements = []
    {
      std::unordered_map<std::string, std::string> result;
      for (const auto* stockName : { "smallFont", "normalFont", "boldFont", "bigFont", "extraBigFont", "objectiveFont", "hudBigFont", "hudSmallFont" })
      {
        result.emplace(Utils::String::ToLower(std::format("fonts/{}", stockName)), std::format("fonts/ar_{}", stockName));
      }
      return result;
    }();

    if (const auto itr = replacements.find(lowerName); itr != replacements.end())
    {
      // Only use the replacement when the Arabic zone is loaded, never create a default asset
      if (auto* entry = Game::DB_FindXAssetEntry(Game::ASSET_TYPE_FONT, itr->second.data()))
      {
        header = entry->asset.header;
      }
    }

    return header;
  }

  ArabicFonts::ArabicFonts()
  {
    if (Dedicated::IsEnabled() || ZoneBuilder::IsEnabled())
    {
      return;
    }

    LocArabicFonts = Dvar::Register<bool>("loc_arabicFonts", true, Game::DVAR_ARCHIVE, "Replace the game fonts with the Arabic capable fonts from the iw4x_arabic zone. Requires a restart.");

    AssetHandler::OnFind(Game::ASSET_TYPE_FONT, FindFont);
  }
}
