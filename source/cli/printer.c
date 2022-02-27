#include "headers.h"

void	print_help(void)
{
	printf("\n\n%s", LOGINFO);
	printf("\tThe %s`help`%s command Display this help.\n", BOLDWHITE, RESET_F);
	printf("\tThe %s`GET`%s command shows you information about the method GET.\n", BOLDWHITE, RESET_F);
	printf("\tThe %s`DELETE`%s command shows you log information about the method DELETE.\n", BOLDWHITE, RESET_F);
	printf("\tThe %s`root`%s command shows you all information log.\n", BOLDWHITE, RESET_F);
	printf("\tThe %s`clear`%s command clear the terminal screen.\n", BOLDWHITE, RESET_F);
	printf("\tThe %s`exit`%s command exit Logviewer.\n\n", BOLDWHITE, RESET_F);
	return ;
}

void	print_get(void)
{
	printf("\n\t%sMethod:\tGET%s\n", BOLDGREEN, RESET_F);
	printf("\t*****************************\n");
	printf("\t*  %sPATH%s    *%s Total Requests%s *\n", BOLDWHITE, RESET_F, BOLDWHITE, RESET_F);
	printf("\t*****************************\n");
	printf("\t*    /     *       %d       *\n", g_viewer.get.root);
	printf("\t*****************************\n");
	printf("\t*  /id/    *       %d        *\n", g_viewer.get.id);
	printf("\t*****************************\n");
	printf("\t* /alias/  *       %d        *\n", g_viewer.get.alias);
	printf("\t*****************************\n");
}

void	print_delete(void)
{
	printf("\n\t%sMethod:\tDELETE%s\n", BOLDGREEN, RESET_F);
	printf("\t*****************************\n");
	printf("\t*  %sPATH%s    *%s Total Requests%s *\n", BOLDWHITE, RESET_F, BOLDWHITE, RESET_F);
	printf("\t*****************************\n");
	printf("\t*  /id/    *       %d        *\n", g_viewer.delete.id);
	printf("\t*****************************\n");
	printf("\t* /alias/  *       %d        *\n", g_viewer.delete.alias);
	printf("\t*****************************\n");
}

void	print_root(void)
{
	printf("\n\t%sroot%s\n", BOLDGREEN, RESET_F);
	printf("\t******************************************\n");
	printf("\t*  %sMETHOD    *  PATH    * Total Requests%s *\n", BOLDWHITE, RESET_F);
	printf("\t******************************************\n");
	printf("\t*    GET     *    /     *       %d       *\n", g_viewer.get.root);
	printf("\t******************************************\n");
	printf("\t*    GET     *  /id/    *       %d        *\n", g_viewer.get.id);
	printf("\t******************************************\n");
	printf("\t*    GET     * /alias/  *       %d        *\n", g_viewer.get.alias);
	printf("\t******************************************\n");
	printf("\t*  DELETE    *  /id/    *       %d        *\n", g_viewer.delete.id);
	printf("\t******************************************\n");
	printf("\t*  DELETE    * /alias/  *       %d        *\n", g_viewer.delete.alias);
	printf("\t******************************************\n");
}
