@echo off
echo ========================================
echo     COMPILING CARO GAME...
echo ========================================

set JDBC_JAR=lib\postgresql-42.7.8.jar

REM Compile
javac -cp "%JDBC_JAR%" -d out src\com\caro\Main.java src\com\caro\model\*.java src\com\caro\database\*.java src\com\caro\ui\*.java src\com\caro\util\*.java

if %ERRORLEVEL% NEQ 0 (
    echo.
    echo ========================================
    echo     COMPILATION FAILED!
    echo ========================================
    pause
    exit /b 1
)

echo.
echo ========================================
echo     COMPILATION SUCCESSFUL!
echo     STARTING GAME...
echo ========================================
echo.

REM Run
java -cp "out;%JDBC_JAR%" com.caro.Main

pause