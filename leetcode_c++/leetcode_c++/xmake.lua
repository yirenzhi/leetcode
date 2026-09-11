add_rules("mode.debug", "mode.release")

target("leetcode_c++")
    set_kind("static")
    add_files("LeetCode.cpp")

target("start")
    set_kind("binary")
    add_files("start.cpp")
    add_deps("leetcode_c++")

    -- 构建前自动扫描所有题目头文件，生成聚合头 all_problems.h
    -- 新增题目只需在 code*/*.h 里写 REGISTER_SOLUTION 宏，无需改 start.cpp
    before_build(function (target)
        local files = os.files("code*/*.h") or {}
        local adv = os.files("AdventureMode/**/*.h") or {}
        for _, f in ipairs(adv) do table.insert(files, f) end
        table.sort(files)
        local content = "#pragma once\n"
        for _, f in ipairs(files) do
            content = content .. '#include "' .. f .. '"\n'
        end
        io.writefile("all_problems.h", content)
        print("已生成 all_problems.h, 共 " .. #files .. " 个题目头文件")
    end)

--
-- If you want to known more usage about xmake, please see https://xmake.io
--
-- ## FAQ
--
-- You can enter the project directory firstly before building project.
--
--   $ cd projectdir
--
-- 1. How to build project?
--
--   $ xmake
--
-- 2. How to configure project?
--
--   $ xmake f -p [macosx|linux|iphoneos ..] -a [x86_64|i386|arm64 ..] -m [debug|release]
--
-- 3. Where is the build output directory?
--
--   The default output directory is `./build` and you can configure the output directory.
--
--   $ xmake f -o outputdir
--   $ xmake
--
-- 4. How to run and debug target after building project?
--
--   $ xmake run [targetname]
--   $ xmake run -d [targetname]
--
-- 5. How to install target to the system directory or other output directory?
--
--   $ xmake install
--   $ xmake install -o installdir
--
-- 6. Add some frequently-used compilation flags in xmake.lua
--
-- @code
--    -- add debug and release modes
--    add_rules("mode.debug", "mode.release")
--
--    -- add macro definition
--    add_defines("NDEBUG", "_GNU_SOURCE=1")
--
--    -- set warning all as error
--    set_warnings("all", "error")
--
--    -- set language: c99, c++11
--    set_languages("c99", "c++11")
--
--    -- set optimization: none, faster, fastest, smallest
--    set_optimize("fastest")
--
--    -- add include search directories
--    add_includedirs("/usr/include", "/usr/local/include")
--
--    -- add link libraries and search directories
--    add_links("tbox")
--    add_linkdirs("/usr/local/lib", "/usr/lib")
--
--    -- add system link libraries
--    add_syslinks("z", "pthread")
--
--    -- add compilation and link flags
--    add_cxflags("-stdnolib", "-fno-strict-aliasing")
--    add_ldflags("-L/usr/local/lib", "-lpthread", {force = true})
--
-- @endcode
--

