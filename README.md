# Slimer
Slimer provides the sleep, msleep, and usleep functions to Lua as a C extension. It also provides a high resolution (&lt;1us) clock that can be used for timing purposes.
It is currently supported on Windows only.

## Installation instructions
Slimer uses the Lua C API, which means that you can't simply load the module as you normally would using "require". 
