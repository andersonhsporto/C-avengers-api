FROM	ubuntu:rolling

RUN		apt-get update

RUN apt-get install -y mariadb-server
RUN apt-get install -y libreadline6-dev python3 make
RUN apt-get install -y libmicrohttpd-dev libmbedtls-dev
RUN apt-get install -y libcurl4-openssl-dev gcc
RUN apt-get install -y glibc-source libmysqlclient-dev

EXPOSE 4242

COPY . /usr/src/api
WORKDIR /usr/src/api

ENTRYPOINT ["./init.sh"]