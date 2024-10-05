# CLEO Library for GTA San Andreas (Windows PC)

CLEO is a hugely popular extensible library plugin which brings new possibilities in scripting for the game Grand Theft Auto: San Andreas by Rockstar Games, allowing the use of thousands of unique mods which change or expand the gameplay. You may find more information about CLEO on the official website https://cleo.li

## Installation

An ASI loader is required for CLEO 5 to work. CLEO 5 is bundled with several popular ASI Loaders ([Silent's ASI Loader](https://cookieplmonster.github.io/mods/gta-sa/#asiloader) and [Ultimate ASI Loader](https://github.com/ThirteenAG/Ultimate-ASI-Loader/)).

Follow the instructions on the [release page](https://github.com/cleolibrary/CLEO5/releases) to choose a bundle that works best for you.

The ASI Loader replaces one original game file: `vorbisFile.dll` - be sure to make a backup of this file.
CLEO itself does not replace any game file, however the following files and folders are added:

- cleo\ (CLEO script directory)
- cleo\\.config\sa.json (opcodes info file)
- cleo\cleo_plugins\SA.Audio.cleo (audio playback utilities powered by BASS.dll library)
- cleo\cleo_plugins\SA.DebugUtils.cleo (script debugging utilities plugin)
- cleo\cleo_plugins\SA.FileSystemOperations.cleo (disk drive files related operations plugin)
- cleo\cleo_plugins\SA.IniFiles.cleo (.ini config files handling plugin)
- cleo\cleo_plugins\SA.Math.cleo (additional math operations plugin)
- cleo\cleo_plugins\SA.MemoryOperations.cleo (memory and .dll libraries utilities plugin)
- cleo\cleo_plugins\SA.Text.cleo (text processing plugin)
- cleo\cleo_saves\ (CLEO save directory)
- cleo\cleo_text\ (CLEO text directory)
- modloader\.data\plugins\CLEO5_Provider.dll (CLEO5 ModLoader plugin)
- cleo.asi (core library)
- bass.dll (audio engine library)

All plugins are optional, however they may be required by various CLEO scripts.

## CLEO Scripts

CLEO allows the installation of 'CLEO scripts', which often use the extension '.cs'. These third-party scripts are entirely user-made and are in no way supported by the developers of this library. While CLEO itself should work in a wide range of game installations, individual scripts are known to have their own compatibility restrictions and can not be guaranteed to work.
CLEO scripts can be found on Grand Theft Auto fansites and modding sites such as:

- https://libertycity.net/files/gta-san-andreas/mods/cleo-scripts/
- https://www.gtainside.com/en/sanandreas/mods-322/
- http://hotmist.ddo.jp/cleomod/index.html
- https://zazmahall.de/CLEO.htm

## Compatibility Mode

CLEO is continually being improved and extended over time. In very rare circumstances, new major releases may break some older scripts. To fix this, CLEO provides a 'compatibility mode' to closely emulate behavior of previous versions and improve stability of old scripts. 
- To run a script with maximum compatibility with 'CLEO 4', change the script extension from `.cs` to `.cs4`.
- To run a script with maximum compatibility with 'CLEO 3', change the script extension from `.cs` to `.cs3`. 

## Credits

The author and original developer of the CLEO library is Seemann. Development of CLEO 4 was led by Alien and Deji, later turned into CLEO 5 by Miran. Today the CLEO library is an open-source project being maintained at https://github.com/cleolibrary

Special thanks to:

- Stanislav Golovin (a.k.a. listener) for his great work in exploration of the GTA series.
- NTAuthority and LINK/2012 for additional support with CLEO 4.3.
- mfisto for the alpha-testing of CLEO 4, his support and advices.
- 123nir for the alpha-testing of CLEO 5.0.0, troubleshooting and valuable bug reports.

The developers are not affiliated with Take 2 Interactive or Rockstar Games.
By using this product or any of the additional products included you take your own personal responsibility for any negative consequences should they arise.
