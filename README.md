# ZXM movie maker. Scripts to create ZXM movie files.

Requirements: ffmpeg, scrplus (https://sourceforge.net/projects/scrplus/), make, C compiler.

Compile makezxmvideo:

make

Convert some video file by ffmpeg:

ffmpeg -i somevideo.mp4 -vf fps=25,scale=256:192 out%09d.png

generate somevideo.zxm:

make -j$(nproc) somevideo.zxm

It will take some time. Put somevideo.zxm to your esxdos filesystem.
To clean up delete *.png and *.scr.
