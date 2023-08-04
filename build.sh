#!/bin/bash

PROJ="12-making-class-objects-act-like-values"
MODE="Debug"

while getopts "p:m:" option; do
  case $option in
    p ) PROJ=$OPTARG
    echo "PROJ: $PROJ"
    ;;
    m ) MODE=$OPTARG
    echo "MODE: $MODE"
    ;;
  esac
done

echo $PROJ
echo $MODE

rm -rf generated build

premake5 gmake2

pushd generated
make -j$(nproc)
../build/bin/$PROJ/$MODE/$PROJ
popd
