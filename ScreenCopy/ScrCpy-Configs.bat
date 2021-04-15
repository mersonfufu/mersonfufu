@echo off
cd ScrCpy
scrcpy -f --lock-video-orientation=270 --record=Video_e0001.mp4
taskkill /f /im adb*