FROM ubuntu:latest

RUN apt-get update && \
    # Default Ubuntu GCC, GDB and CMake
    apt-get install -y apt-transport-https ca-certificates gnupg software-properties-common wget curl git vim unzip tar gcc g++ cmake gdb libreadline6-dev texinfo && \
    apt-get update && \
    # Clone and initialize vcpkg
    git clone https://github.com/microsoft/vcpkg.git && \
    cd vcpkg && \
    ./bootstrap-vcpkg.sh && \
    ./vcpkg integrate install && \
    # Install external dependencies
    ./vcpkg install range-v3 && \
    # Clean up
    apt-get clean autoclean && \
    apt-get autoremove -y && \
    rm -rf /var/lib/apt/lists/* && \
    # Create the develop user for security reasons
    useradd -ms /bin/bash develop && \
    echo "develop   ALL=(ALL:ALL) ALL" >> /etc/sudoers

# gdbserver port
EXPOSE 2000

USER develop
WORKDIR /home/develop/dev
VOLUME /home/develop/dev
