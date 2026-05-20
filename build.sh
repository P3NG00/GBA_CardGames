#!/bin/bash

podman build \
    --tag "gba-cardgames-old" \
    .

GBA_DEBUG=false
if [ "$GBA_DEBUG" = false ]; then
    podman run \
        --name "gba-cardgames-old" \
        --replace \
        "gba-cardgames-old"

    podman cp "gba-cardgames-old":/gba/gba.gba .
else
    podman run \
        --name "gba-cardgames-old" \
        --replace \
        --interactive --tty --entrypoint /bin/bash \
        "gba-cardgames-old"
fi
