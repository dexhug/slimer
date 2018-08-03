##### Welcome to the Slimer Module!
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
usleep (100) -- sleep for .1 milliseconds

local startTime = slimer.clock() -- get current time
--[[
    EXECUTE SOME CODE
  ]]
local endTime = slimer.clock() -- get end time

print("Total time elapsed during code block:", (endTime - startTime) * period * 1000, "milliseconds")
```

## Installation instructions
Slimer uses the Lua C API, which means that you can't simply load the module as you normally would using "require". You have to first compile the module into an executable that Lua can use. Creating a DLL through Microsoft Visual Studio is the easiest, so I have provided instructions for this method. If you are aware of the other compilation methods you are probably already knowledgeable enough to use them. Please note that you need your own compiled version of Lua either as a standalone or an embedded system, and you will require the Lua header files, an import library (.lib file), and DLL.

#### Creating a DLL with Visual Studio
