@echo off

set output=th0.scl
set outspg=th0.spg

set spgpack=0
set spgdesc="Lost donation box incident"
set title="Girls are praying..."

set palette16.0=gfx\sprites.bmp
set palette256.2=gfx\bg1.bmp
set palette256.3=gfx\bg8.bmp
set palette256.4=gfx\final.bmp

set palette256.1=gfx\title.bmp
set palette256.0=gfx\font.bmp
set image256.2=gfx\bg1.bmp
set image256.3=gfx\bg2.bmp
set image256.4=gfx\bg3.bmp
set image256.5=gfx\bg4.bmp
set image256.6=gfx\bg5.bmp
set image256.7=gfx\bg6.bmp
set image256.8=gfx\bg7.bmp
set image256.9=gfx\bg8.bmp
set image256.10=gfx\final.bmp

set image256.1=gfx\title.bmp
set image256.0=gfx\font.bmp
set sprites=gfx\sprites.bmp
set soundfx=music\sfx.afb

set music.0=music\th0ea1.pt3
set music.1=music\nwz.pt3
set music.2=music\ea2.pt3
set music.3=music\cirno.pt3
set music.4=music\sisters.pt3
set music.5=music\glassed.pt3
set music.6=music\hard.pt3
set music.7=music\zonk.pt3
set music.8=music\th0pn.pt3
set music.9=music\win.pt3
set sample.0=


call ..\evosdk\_compile.bat
@if %error% ==0 ..\evosdk\tools\unreal_evo\unreal %outspg%

