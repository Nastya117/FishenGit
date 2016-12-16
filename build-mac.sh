#!/bin/sh

qmake
make
macdeployqt FishServ/FishServ.app
macdeployqt FishCli/FishCli.app
zip FishenGit.zip FishServ/FishServ.app FishCli/FishCli.app
