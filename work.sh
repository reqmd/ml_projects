#!/bin/bash

# Получение задачи из именованного канала
while true; do
  if [ -p pipe1 ]; then
    task=$(cat pipe1)
    rm pipe1
    break
  else
    # Получение задачи из очереди сообщений
    msg_id=$(ipcrm -M 1)
    msginfo -i $msg_id
    msg=$(msgrcv -r $msg_id 1 1 -t 10)
    if [ -n "$msg" ]; then
      task=$msg
      break
    fi
  fi
done

# Выполнение вычислений
num1=$(echo "$task" | cut -d' ' -f1)
op=$(echo "$task" | cut -d' ' -f2)
num2=$(echo "$task" | cut -d' ' -f3)

result=$(eval "echo \"scale=2; $num1 $op $num2\" | bc")

# Отправка результата пользователю
echo "Результат: $result"
