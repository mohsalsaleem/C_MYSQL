#include<my_global.h>
#include<mysql.h>

void finish_with_error(MYSQL *con)
{
	fprintf(stderr,"%s\n",mysql_error(con));
	mysql_close(con);
	exit(0);
}


int main(int argc, char **argv)
{
	MYSQL *con = mysql_init(NULL);
	
	if(con == NULL)
	{
		fprintf(stderr,"%s\n",mysql_error(con));
		exit(0);
	}
	if(mysql_real_connect(con,"localhost","root","saleem09","testdb",0,NULL,0) == NULL)
	{
		finish_with_error(con);
	}

	if(mysql_query(con,"DROP table if exists TEMP"))
	{
		finish_with_error(con);
	}

	if(mysql_query(con,"CREATE TABLE TEMP(Id INT, City TEXT, Temp INT)"))
	{
		finish_with_error(con);
	}

	if(mysql_query(con,"INSERT INTO TEMP VALUES(1, 'Chennai' , 72)"))
	{
		finish_with_error(con);
	}

	 if(mysql_query(con,"INSERT INTO TEMP VALUES(2, 'Madurai' , 90)"))
        {
                finish_with_error(con);
        }
	mysql_close(con);
	exit(0);

}
