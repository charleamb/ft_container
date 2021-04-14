# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chgilber <charleambg@gmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/13 18:33:41 by chgilber          #+#    #+#              #
#    Updated: 2021/04/13 18:35:00 by chgilber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LAGS =			-Wall -Werror -Wextra -std=c++98# -pedantic

STD =			-D MODE=std
STD_PAIR =			-D PAIR=std::pair

FT =			-D MODE=ft
FT_PAIR =			-D PAIR=Pair

CC =			clang++

vector:
				$(CC) $(FLAGS) $(STD) Vector/main_vector.cpp -o vector
				./vector > result_std
				rm ./vector
				$(CC) $(FLAGS) $(FT) Vector/main_vector.cpp -o vector
				./vector > result_ft
				rm ./vector
				diff -s result_ft result_std > result_diff
clean:
				rm result*
