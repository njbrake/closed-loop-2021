
FROM ubuntu:latest

# In a nutshell, apt-get update doesn't actually install new versions of software.
# Instead, it updates the package lists for upgrades for packages that need upgrading, as well as new packages that have just come to the repositories.
RUN apt-get update

# Install Node and NPM, not picky 
RUN apt-get install -y nodejs cmake
RUN apt-get install -y npm

# ZScalar so that it works in 3M network. If you are not on 3M network, delete these lines.
ARG bundleLocation=/root/cacert-bundle.pem
COPY certs/cacert-bundle.pem ${bundleLocation}
ENV NODE_EXTRA_CA_CERTS=${bundleLocation}

# Add the source code into the container in location /opt/closedLoop
COPY . /opt/closedLoop
WORKDIR /opt/closedLoop

RUN npm install --global yarn


