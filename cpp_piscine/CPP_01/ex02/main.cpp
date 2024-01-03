/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:40:36 by alafranc          #+#    #+#             */
/*   Updated: 2021/09/09 14:51:29 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main() {
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;
    std::cout << "Address str:" << std::endl << "With str: " << &string << std::endl << "With ptr: " << stringPTR << std::endl << "With ref: " << &stringREF << std::endl;
    std::cout << "STRING:" << std::endl << "With ptr: " << *stringPTR << std::endl << "With ref: " << stringREF << std::endl;
}