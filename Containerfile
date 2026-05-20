FROM docker.io/devkitpro/devkitarm:latest

ARG GIT_BUTANO_URL="https://github.com/GValiente/butano" \
    GIT_BUTANO_HASH="a0823455c6e4c51037ce6beb892397cd0bba4bf6"

RUN git clone --no-checkout "${GIT_BUTANO_URL}" /butano \
    && cd /butano \
    && git checkout "${GIT_BUTANO_HASH}"

WORKDIR /gba

COPY . .

ENTRYPOINT make -j$(nproc)
