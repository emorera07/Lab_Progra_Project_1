# Build me with
# docker build --tag gtest_lab:latest .

# Define base OS
FROM ubuntu:20.04

ENV TZ=America/Costa_Rica
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime \
    && echo $TZ > /etc/timezone

# Info Labels
LABEL mantainer="emmanuel.morera@ucr.ac.cr"
LABEL version="1.0"
LABEL description="Custome docker image for a Gtest lab"

# Choose user root
USER root

# Install dependencies
RUN apt-get update \
    && apt-get --yes --no-install-recommends install \
        build-essential cmake libgtest-dev \
        libsdl2* guile-2.0 freetype2-demos \
        fonts-dejavu fonts-freefont-ttf \
        ttf-bitstream-vera

# Create project folder
RUN mkdir -p /home/gtest_lab

# Copy local files to container
COPY include /home/gtest_lab/include
COPY data /home/gtest_lab/data
COPY src /home/gtest_lab/src
COPY test /home/gtest_lab/test
COPY README.md /home/gtest_lab/READMe.md

# Compile and copy executable
RUN mkdir -p /home/gtest_lab/build \
    && cd /home/gtest_lab/build \
    && g++ ../src/main.cpp -o voronoi \
        `sdl2-config --cflags --libs` \
        -lSDL2 -lSDL2_image -lSDL2_ttf \
    && cp voronoi /usr/bin/run_unittest \
    && chmod +x /usr/bin/run_unittest
