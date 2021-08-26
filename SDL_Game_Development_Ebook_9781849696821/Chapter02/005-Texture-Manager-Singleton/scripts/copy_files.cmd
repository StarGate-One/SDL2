setlocal
set cmd_Configuration=%1
set cmd_OutDir=%2

goto %cmd_Configuration%

:Debug
echo %cmd_Configuration% %cmd_OutDir%
echo xcopy /d /f /h /i /r /v /y "..\..\..\..\_vcpkg\%cmd_Configuration%\bin\SDL2d.*" "%cmd_OutDir%"
xcopy /d /f /h /i /r /v /y "..\..\..\..\_vcpkg\%cmd_Configuration%\bin\SDL2d.*" "%cmd_OutDir%"
echo xcopy /d /f /h /i /r /v /y "..\..\..\..\_vcpkg\%cmd_Configuration%\bin\SDL2_image.*" "%cmd_OutDir%"
xcopy /d /f /h /i /r /v /y "..\..\..\..\_vcpkg\%cmd_Configuration%\bin\SDL2_image.*" "%cmd_OutDir%"
echo xcopy /d /f /h /i /r /v /y "..\..\..\..\_vcpkg\%cmd_Configuration%\bin\libpng16d.*" "%cmd_OutDir%"
xcopy /d /f /h /i /r /v /y "..\..\..\..\_vcpkg\%cmd_Configuration%\bin\libpng16d.*" "%cmd_OutDir%"
echo xcopy /d /f /h /i /r /v /y "..\..\..\..\_vcpkg\%cmd_Configuration%\bin\jpeg62.*" "%cmd_OutDir%"
xcopy /d /f /h /i /r /v /y "..\..\..\..\_vcpkg\%cmd_Configuration%\bin\jpeg62.*" "%cmd_OutDir%"
echo xcopy /d /f /h /i /r /v /y "..\..\..\..\_vcpkg\%cmd_Configuration%\bin\tiffd.*" "%cmd_OutDir%"
xcopy /d /f /h /i /r /v /y "..\..\..\..\_vcpkg\%cmd_Configuration%\bin\tiffd.*" "%cmd_OutDir%"
echo xcopy /d /f /h /i /r /v /y "..\..\..\..\_vcpkg\%cmd_Configuration%\bin\webpd.*" "%cmd_OutDir%"
xcopy /d /f /h /i /r /v /y "..\..\..\..\_vcpkg\%cmd_Configuration%\bin\webpd.*" "%cmd_OutDir%"
echo xcopy /d /f /h /i /r /v /y "..\..\..\..\_vcpkg\%cmd_Configuration%\bin\zlibd*.*" "%cmd_OutDir%"
xcopy /d /f /h /i /r /v /y "..\..\..\..\_vcpkg\%cmd_Configuration%\bin\zlibd*.*" "%cmd_OutDir%"
echo xcopy /d /f /h /i /r /v /y "..\..\..\..\_vcpkg\%cmd_Configuration%\bin\lzmad.*" "%cmd_OutDir%"
xcopy /d /f /h /i /r /v /y "..\..\..\..\_vcpkg\%cmd_Configuration%\bin\lzmad.*" "%cmd_OutDir%"


goto end

:Release
echo %cmd_Configuration% %cmd_OutDir%
echo xcopy /d /f /h /i /r /v /y "..\..\..\..\_vcpkg\%cmd_Configuration%\bin\SDL2.*" "%cmd_OutDir%"
xcopy /d /f /h /i /r /v /y "..\..\..\..\_vcpkg\%cmd_Configuration%\bin\SDL2.*" "%cmd_OutDir%"
echo xcopy /d /f /h /i /r /v /y "..\..\..\..\_vcpkg\%cmd_Configuration%\bin\SDL2_image.*" "%cmd_OutDir%"
xcopy /d /f /h /i /r /v /y "..\..\..\..\_vcpkg\%cmd_Configuration%\bin\SDL2_image.*" "%cmd_OutDir%"
echo xcopy /d /f /h /i /r /v /y "..\..\..\..\_vcpkg\%cmd_Configuration%\bin\libpng16.*" "%cmd_OutDir%"
xcopy /d /f /h /i /r /v /y "..\..\..\..\_vcpkg\%cmd_Configuration%\bin\libpng16.*" "%cmd_OutDir%"
echo xcopy /d /f /h /i /r /v /y "..\..\..\..\_vcpkg\%cmd_Configuration%\bin\jpeg62.*" "%cmd_OutDir%"
xcopy /d /f /h /i /r /v /y "..\..\..\..\_vcpkg\%cmd_Configuration%\bin\jpeg62.*" "%cmd_OutDir%"
echo xcopy /d /f /h /i /r /v /y "..\..\..\..\_vcpkg\%cmd_Configuration%\bin\tiff.*" "%cmd_OutDir%"
xcopy /d /f /h /i /r /v /y "..\..\..\..\_vcpkg\%cmd_Configuration%\bin\tiff.*" "%cmd_OutDir%"
echo xcopy /d /f /h /i /r /v /y "..\..\..\..\_vcpkg\%cmd_Configuration%\bin\webp.*" "%cmd_OutDir%"
xcopy /d /f /h /i /r /v /y "..\..\..\..\_vcpkg\%cmd_Configuration%\bin\webp.*" "%cmd_OutDir%"
echo xcopy /d /f /h /i /r /v /y "..\..\..\..\_vcpkg\%cmd_Configuration%\bin\zlib*.*" "%cmd_OutDir%"
xcopy /d /f /h /i /r /v /y "..\..\..\..\_vcpkg\%cmd_Configuration%\bin\zlib*.*" "%cmd_OutDir%"
echo xcopy /d /f /h /i /r /v /y "..\..\..\..\_vcpkg\%cmd_Configuration%\bin\lzma.*" "%cmd_OutDir%"
xcopy /d /f /h /i /r /v /y "..\..\..\..\_vcpkg\%cmd_Configuration%\bin\lzma.*" "%cmd_OutDir%"


:end
endlocal