FROM ubuntu:22.04

SHELL ["/bin/bash", "-c"]

RUN apt-get update && apt-get upgrade -y && apt-get install -y \
  g++ \
  git \
  curl \
  libtool \
  autoconf \
  lbzip2 \
  python3 \
  cmake \
  ninja-build \
  xz-utils \
  texinfo


RUN git clone https://github.com/emscripten-core/emsdk.git /root/third_party/emsdk

RUN cd /root/third_party/emsdk \
    && git pull \ 
    && ./emsdk install latest \ 
    && ./emsdk activate latest \
    && source ./emsdk_env.sh

ENV PATH="$PATH:/root/third_party/emsdk:/root/third_party/emsdk/upstream/emscripten:/root/third_party/emsdk/node/16.20.0_64bit/bin"

RUN curl https://github.com/LibreDWG/libredwg/releases/download/0.12.5/libredwg-0.12.5.tar.gz -o LibreDWG.tar.gz -L \
  && tar -xvf LibreDWG.tar.gz \
  && mv LibreDWG-0.12.5 /root/third_party/LibreDWG \
  && rm LibreDWG.tar.gz

# 编译 LibreDWG
RUN cd /root/third_party/LibreDWG \
  && ./autogen.sh \
  && emconfigure ./configure --disable-bindings --disable-shared \
  && emcmake cmake \
  -GNinja \
  -Bbuild \
  && ninja -C build