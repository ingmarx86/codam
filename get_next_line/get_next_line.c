/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:47:19 by inoteboo          #+#    #+#             */
/*   Updated: 2022/12/18 09:39:59 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void f()
{
	static int calls;

	if (calls == 0)
	calls = 0;
	calls++;
	printf("calls = %d\n", calls);
	
}

void log_message(char *message)
{
	static int total;
	
	if(total == 0)
	total = 0;
	total++;
	
	FILE *logfile = fopen("log.txt", "a");
	if (logfile != NULL)
	{
		fprintf(logfile, "log %d: %s\n", total, message);
		fclose(logfile);
	}
}

int main()
{
	log_message("read data");
	log_message("update data");
	log_message("data error");

	
	
	return (0);
}