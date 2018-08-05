# Welcome to the Slimer Module!
Slimer provides the sleep, msleep, and usleep functions to Lua as a C extension. It also provides a high resolution (&lt;1us) clock that can be used for timing purposes.
It is currently supported on Windows only.

## Usage
```Lua
-- USAGE OF SLIMER IN LUA

-- if your compiled DLL is not already in the Lua path you must add it
package.cpath = "path\\to\\your\\dll\\?.dll" .. package.cpath

-- use the appropriate 64 or 32 bit version for your system
local slimer = require("slimerx64") -- 64 bit
local slimer = require("slimerx86") -- 32 bit

local sleep  = slimer.sleep  -- sleep by seconds
local msleep = slimer.msleep -- sleep by milliseconds
local usleep = slimer.usleep -- sleep by microseconds
-- see docs if you don't understand below
local frequency        = slimer.frequency() -- returns integer indicating frequency of your PerformanceCounter
local currentClockTime = slimer.clock()     -- returns current time since system startup with unit and precision of period
local period           = slimer.period()    -- returns float indicating period of your PerformanceCounter in seconds

sleep(10) -- sleep for 10 seconds
msleep(2400) -- sleep for 2.4 seconds
usleep(100) -- sleep for .1 milliseconds

local startTime = slimer.clock() -- get current time
--[[
    EXECUTE SOME CODE
  ]]
local endTime = slimer.clock() -- get end time

print("Total time elapsed during code block:", (endTime - startTime) * period * 1000, "milliseconds")
```

## Installation instructions
Slimer uses the Lua C API, which means that you cannot simply load the module as you normally would using "require". You have to first compile the module into an executable that Lua can use. Creating a DLL through Microsoft Visual Studio is the easiest, so I have provided instructions for this method. If you are aware of the other compilation methods you are probably already knowledgeable enough to use them. Please note that you need your own compiled version of Lua either as a standalone or an embedded system, and you will require the Lua header files, an import library (.lib file), and a Lua DLL.

#### Creating a DLL with Visual Studio
1. Open Visual Studio and select <b>File</b> --> <b>New</b> --> <b>Project</b>.
2. Look for the <b>Visual C++</b> tab, and select <b>Windows Desktop Wizard</b> (or DLL if you understand the differences).
3. Select <b>Dynamic Link Library</b> from the next dialog box and create the project.
4. Put either the <b>slimerx64</b> or <b>slimerx86</b> C++/C file and the respective header file into the project by selecting <b>Open</b>.
5. In the Solution Explorer, select the project, then on the menu select <b>Project</b> --> <b>Properties</b>.
6. Make sure your configuration is set to <b>All Configurations</b> and the Platform is set to your Slimer bit version.
7. Navigate to the <b>C/C++</b> tab and go to <b>General</b>.
8. Under <b>Additional Include Directories</b>, add the directory path that contains the Lua header files (lua.h, lauxlib.h, etc).
9. Go to <b>Advanced</b> in the same tab, and set <b>Compile As</b> to <b>C</b> if you are using the 32 bit version, and <b>C++</b> for the 64 bit version.
10. Go to the <b>Linker</b> tab and hit <b>General</b>.
11. Under <b>Additional Library Directories</b> add the directory path that contains your Lua5X.lib file (the binaries do not come with this file included, you must have compiled Lua yourself or get the .lib file somewhere). The .lib file must be for the 32 or 64 bit version of Lua depending on which one you are using, and of course you must use the Slimer version that corresponds to that.
12. Under <b>Linker</b> --> <b>Input</b> --> <b>Additional Dependencies</b> add the name of the .lib file.
13. Click <b>OK</b> on the Properties and build your project by selecting <b>Build</b> --> <b>Build Solution</b>.
14. If everything works correctly you can now use "require" as you normally would and use Slimer. Enjoy!

If you run into problems with the stdafx header, you can delete all the extra files that the project automatically created, and then click <b>Project</b> --> <b>Properties</b> --> <b>C/C++</b> --> <b>Precompiled Headers</b> --> <b>Precompiled Header</b> and set it to <b>Not Using Precompiled Headers</b>. Also, make sure the Lua DLL is in a the same directory as your Slimer DLL, or link the path in addition to the above instructions.
