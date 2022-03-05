FROM	ubuntu:rolling

RUN		apt-get update

RUN apt-get install -y mariadb-server
RUN apt-get install -y libreadline6-dev python make
RUN apt-get install -y libmicrohttpd-dev libmbedtls-dev
RUN apt-get install -y libcurl4-openssl-dev gcc
RUN apt-get install -y glibc-source libmysqlclient-dev

EXPOSE 3306
EXPOSE 4242

# LABEL version="1.0"
# LABEL description="MariaDB Server"

# HEALTHCHECK --start-period=5m \
# 	CMD mariadb -e 'SELECT @@datadir;' || exit 1
# CMD service mariadb start

COPY . /usr/src/api
WORKDIR /usr/src/api

ENTRYPOINT ["./avengers_api"]
# CMD ["./avengers_api"]

# RUN ldconfig
# # RUN service mysql stop
# # RUN usermod -d /var/lib/mysql/ mysql
# # RUN /etc/init.d/mysql start
# # RUN /etc/init.d/mysql start

# CMD ["mysqld"]
# CMD ["./avengers_api"]

# RUN touch /var/run/mysqld/mysqld.sock
# RUN touch /var/run/mysqld/mysqld.pid
# RUN chown -R mysql:mysql /var/run/mysqld/mysqld.sock
# RUN chown -R mysql:mysql /var/run/mysqld/mysqld.sock
# RUN chmod -R 644 /var/run/mysqld/mysqld.sock
# RUN service mysql restart