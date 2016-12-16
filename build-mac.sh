#!/bin/sh
version=$1

qmake
make -j4
macdeployqt FishServ/FishServ.app
macdeployqt FishCli/FishCli.app
zip FishenGit-mac-${version}.zip FishServ/FishServ.app FishCli/FishCli.app
