#!/bin/bash
git pull origin develop
(nohup npm run start:dev &)