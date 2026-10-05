# IW4x Arabic | IW4x بالعربي

Arabic language support for [IW4x](https://github.com/iw4x/iw4x-client), the Call of Duty: Modern Warfare 2 (2009) multiplayer client.

دعم كامل للغة العربية في IW4x لعبة Call of Duty: Modern Warfare 2 (2009).

## Features | المميزات

- Arabic text rendering with joined letters and right-to-left ordering, including mixed Arabic, English and numbers
- Noto Kufi Arabic font for menus and the HUD
- Over 6,800 game strings translated to Arabic
- Right-aligned menu text
- Arabic typing in the chat box

---

- عرض النص العربي بحروف متصلة ومن اليمين إلى اليسار، مع دعم النصوص المختلطة بالإنجليزية والأرقام
- خط Noto Kufi Arabic للقوائم وواجهة اللعب
- ترجمة أكثر من 6800 نص في اللعبة
- محاذاة نصوص القوائم إلى اليمين
- الكتابة بالعربي في الدردشة

## Installation | التثبيت

You need a working IW4x installation.

1. Download `IW4x-Arabic.zip` from the [Releases](../../releases) page.
2. Extract it into your IW4x folder (the folder that contains `iw4x.exe`) and replace the files when asked.
3. Start the game with `iw4x-arabic.bat`.

Start the game with `iw4x-arabic.bat` or `iw4x.exe`, not the IW4x launcher: the launcher updates `iw4x.dll` and replaces the Arabic version.

---

تحتاج إلى نسخة IW4x تعمل.

1. حمّل `IW4x-Arabic.zip` من صفحة [الإصدارات](../../releases).
2. فك الضغط داخل مجلد IW4x (المجلد الذي يحتوي على `iw4x.exe`) ووافق على استبدال الملفات.
3. شغّل اللعبة من `iw4x-arabic.bat`.

شغّل اللعبة من `iw4x-arabic.bat` أو `iw4x.exe` وليس من مشغّل IW4x، لأن المشغّل يحدّث `iw4x.dll` ويستبدل النسخة العربية.

## Settings | الإعدادات

| Command | Description |
|---|---|
| `loc_translation arabic` | Use the Arabic translation (`""` for English) |
| `loc_reloadTranslation` | Reload the translation file without restarting |
| `loc_arabicFonts 0/1` | Use the Arabic fonts (restart required) |
| `loc_rightAlignMenus 0/1` | Right-align Arabic menu text |
| `loc_dumpStrings` | Save every loaded game string to `userraw/localizedstrings/dump.json` |

To type Arabic in the chat, switch Windows to an Arabic keyboard layout.

للكتابة بالعربي في الدردشة، غيّر لغة لوحة المفاتيح في ويندوز إلى العربية.

## Improving the translation | تحسين الترجمة

The translation is in [`tools/arabic/translation/arabic.json`](tools/arabic/translation/arabic.json). Edit it, copy it to `userraw/localizedstrings/arabic.json` in your game folder and run `loc_reloadTranslation` in the console to see your changes.

Keep placeholders such as `&&1`, `%s`, `[{+attack}]` and color codes like `^3` in your translation. Check a translation with:

```
python tools/arabic/check_translation.py <folder with english.json and arabic.json>
```

`english.json` is created from your own game files with `loc_dumpStrings` or `tools/arabic/extract_strings.py`.

الترجمة موجودة في الملف [`tools/arabic/translation/arabic.json`](tools/arabic/translation/arabic.json). عدّله وانسخه إلى `userraw/localizedstrings/arabic.json` داخل مجلد اللعبة، ثم اكتب `loc_reloadTranslation` في الكونسول لرؤية التغييرات. حافظ على الرموز مثل `&&1` و`%s` و`[{+attack}]` وأكواد الألوان مثل `^3`.

## Building | البناء

The client is built like upstream IW4x (see [README.md](README.md)), with Visual Studio 2022:

```
tools\premake5.exe vs2022
```

Then build `build\iw4x.sln` (Release, Win32).

The font zone is built from the Noto Kufi Arabic font:

1. `python tools/arabic/build_arabic_fonts.py NotoKufiArabic[wght].ttf out` (needs `pip install fonttools`)
2. Copy `out/userraw` and `out/zone_source` into the game folder.
3. Run `iw4x.exe -zonebuilder -stdout +buildzone iw4x_arabic`.
4. Copy `zonebuilder_out/iw4x_arabic.ff` to `zone/english/`.

## Credits | الشكر

- [IW4x](https://github.com/iw4x/iw4x-client) and its contributors
- [Noto Kufi Arabic](https://fonts.google.com/noto/specimen/Noto+Kufi+Arabic), licensed under the SIL Open Font License 1.1

## License | الرخصة

GPL-3.0, like IW4x. See [LICENSE](LICENSE). The font is licensed under the SIL Open Font License 1.1.
