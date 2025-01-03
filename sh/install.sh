#!/bin/sh

if [ "$(command -v scp)" = "" ]; then
  printf "%s\n" "scp is not installed. Please install it."
  exit 1
fi

if [ -z "${BIN}" ]; then
  printf "%s\n" "BIN is not set. Please set it."
  exit 1
fi

cd "$(dirname ${BIN})" || exit 1
${BIN} no-open || exit 1

[ -z "${USERNAME}" ] && USERNAME="$(whoami)"

printf "%s\n" "Command: scp -r ./* \"${USERNAME}@${IP_ADDRESS}:${LOCATION}\""
scp -r ./out/* "${USERNAME}@${IP_ADDRESS}:${LOCATION}" || exit 1

exit 0