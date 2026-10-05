#pragma once

namespace Components
{
  class ArabicFonts : public Component
  {
  public:
    // Zone holding the Arabic capable replacements, named "fonts/ar_<stock name>"
    static constexpr auto ZONE_NAME = "iw4x_arabic";

    ArabicFonts();

  private:
    static Dvar::Var LocArabicFonts;

    static Game::XAssetHeader FindFont(Game::XAssetType type, const std::string& name);
  };
}
