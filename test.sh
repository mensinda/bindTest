#!/bin/bash

bashCB() {
  msg1 "BASH Callback: $2, $3"
  $1 $(( $2 * $3 ))
}

source "$(dirname "$0")/utils/loader.sh"
loadBashUtils

for i in "$(dirname "$0")/bind1/"*.sh; do
  source "$i"
done

[ ! -d "$(dirname "$0")/FIFO" ] && mkdir "$(dirname "$0")/FIFO"

Bind1 binding "$(dirname "$0")/bind1" "$(dirname "$0")/FIFO"
binding . bbind_compile
binding . bbind_start

msg1 "Testing function calls"
binding . funcF "4" "Hello World" "3"
binding . funcF "$OUT_2" "Hello World" "3"
binding . sumArray "4 3 2 500 666000" "5"

msg1 "Testing Pointers"
binding . newTestStruct
PTR="$OUT_0"
binding . printTestStruct "$PTR"
binding . getString2
msg2 "OUT: $OUT_1"

msg1 "Testing function pointes (callbacks)"
binding . setFPTR "$PTR" "bashCB"
binding . call    "$PTR" "2" "5"

binding . freeTestStruct  "$PTR"

binding destruct

[ -e "$(dirname "$0")/FIFO" ] && rm -rf "$(dirname "$0")/FIFO"
