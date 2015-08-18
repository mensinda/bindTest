#!/bin/bash

source "$(dirname "$0")/utils/loader.sh"
loadBashUtils

for i in "$(dirname "$0")/bind1/"*.sh; do
  source "$i"
done

Bind1 binding "$(dirname "$0")/bind1" "$(dirname "$0")/bind1"
binding . bbind_compile
binding . bbind_start

binding . funcF "4" "Hello World" "3"
binding . funcF "$OUT_2" "Hello World" "3"
binding . sumArray "4 3 2 500 666000" "5"

binding destruct
