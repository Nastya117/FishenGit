#!/bin/sh
version=$1

qmake
make -j4
#macdeployqt FishServ/FishServ.app
#macdeployqt FishCli/FishCli.app
tar -zcvf fishen-git-mac-${version}.tar.gz FishServ/FishServ.app FishCli/FishCli.app
