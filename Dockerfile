FROM ubuntu:latest

RUN apt-get update

# Node and NPM
RUN apt-get install -y nodejs cmake
RUN apt-get install -y npm

# ZScalar
ARG bundleLocation=/root/cacert-bundle.pem
COPY certs/cacert-bundle.pem ${bundleLocation}
ENV NODE_EXTRA_CA_CERTS=${bundleLocation}

COPY . /opt/loopy
WORKDIR /opt/loopy

RUN npm install
