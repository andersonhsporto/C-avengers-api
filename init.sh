#!/bin/bash
# service mariadb start
# mariadb -e "CREATE USER 'stark'@localhost IDENTIFIED BY '123'"
# mariadb -e "GRANT ALL PRIVILEGES ON * . * TO 'stark'@'localhost'"
# mariadb -e "CREATE DATABASE api_vingadores"
make
./avengers_api