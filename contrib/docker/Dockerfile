FROM debian:jessie
MAINTAINER pavik - https://github.com/pavik

ENV COLX_VERSION=1.0.0 \
 COLX_USER=colx

ENV COLX_URL=https://github.com/ColossusCoinXT/ColossusCoinXT/releases/download/v$COLX_VERSION-linux/ColossusCoinXT-$COLX_VERSION-x86_64-linux-gnu.tar.gz \
 COLX_CONF=/home/$COLX_USER/.ColossusCoinXT/ColossusCoinXT.conf \
 COLX_CONF_URL=https://raw.githubusercontent.com/ColossusCoinXT/ColossusCoinXT/master/ColossusCoinXT.conf

RUN apt-get -qq update && \
apt-get install -yq wget ca-certificates pwgen && \
rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/* && \
wget $COLX_URL -O /tmp/colx.tar.gz && \
mkdir -p /opt && \
cd /opt && \
tar xvzf /tmp/colx.tar.gz && \
rm /tmp/colx.tar.gz && \
ln -sf colx-$COLX_VERSION colx && \
ln -sf /opt/colx/bin/colxd /usr/local/bin/colxd && \
ln -sf /opt/colx/bin/colx-cli /usr/local/bin/colx-cli && \
ln -sf /opt/colx/bin/colx-tx /usr/local/bin/colx-tx && \
adduser --uid 1000 --system ${COLX_USER} && \
mkdir -p /home/${COLX_USER}/.ColossusCoinXT/ && \
chown -R ${COLX_USER} /home/${COLX_USER} && \
echo "success: $COLX_CONF"

USER colx
RUN wget $COLX_CONF_URL -O $COLX_CONF && \
    sed -i -e 's/\*your$username\*/colx/g' ${COLX_CONF} && \
    sed -i -e 's/\*your$password\*/'`pwgen 32 1`'/g' ${COLX_CONF} && \
    echo "Success"

EXPOSE 51572
VOLUME ["/home/colx/.ColossusCoinXT"]
WORKDIR /home/colx

ENTRYPOINT ["/usr/local/bin/colxd"]