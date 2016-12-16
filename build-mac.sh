#!/bin/sh
version=$1

qmake
make -j4
macdeployqt FishServ/FishServ.app
iacdeployqt FishCli/FishCli.app
zip FishenGit-mac-${version}.zip -r FishServ/FishServ.app FishCli/FishCli.app
