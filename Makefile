# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chgilber <charleambg@gmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/13 18:33:41 by chgilber          #+#    #+#              #
#    Updated: 2021/04/19 08:43:26 by chgilber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LAGS =			-Wall -Werror -Wextra -std=c++98# -pedantic

STD =			-D MODE=std
STD_PAIR =			-D PAIR=std::pair

FT =			-D MODE=ft
FT_PAIR =			-D PAIR=Pair

CC =			clang++

vectortest:
				$(CC) $(FLAGS) $(STD) Vector/main_vector.cpp -o vectortest
				./vectortest > result_std
				rm ./vectortest
				$(CC) $(FLAGS) $(FT) Vector/main_vector.cpp -o vectortest
				./vectortest > result_ft
				rm ./vectortest
				diff -s result_ft result_std > result_diff
listtest:
				$(CC) $(FLAGS) $(STD) List/main_list.cpp -o listtest
				./listtest	> result_std
				rm  listtest
				$(CC) $(FLAGS) $(FT) List/main_list.cpp -o listtest
				./listtest	> result_ft
				rm  listtest
				diff -s result_ft result_std > result_diff
clean:
				rm result*
