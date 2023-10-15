#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>//has the sock structure


// Struct to hold user data (in-memory database)
struct User {
    char username[255];
    char password[255];
    char role[10]; // Role: Admin, Student, or Faculty
};



int authenticateUser(struct User users[], int numUsers, const char* username, const char* password, const char* expectedRole) {
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 &&
            strcmp(users[i].password, password) == 0 &&
            strcmp(users[i].role, expectedRole) == 0) {
            return 1; // Authentication successful
        }
    }
    return 0; // Authentication failed
}

void login(int new_socket){
	               char username[255], password[255], role[10];
        recv(new_socket, username, sizeof(username), 0);
        recv(new_socket, password, sizeof(password), 0);
        recv(new_socket, role, sizeof(role), 0);
	

	struct User users[] = {
        {"admin", "adminpassword", "Admin"},
        {"user1", "password1", "Student"},
        {"user2", "password2", "Student"},
        {"prof1", "faculty123", "Faculty"},
        // Add more users as needed
    };
    int numUsers = sizeof(users) / sizeof(users[0]);


        // Authenticate the user based on their role
        if (strcmp(role, "Admin") == 0) {
            if (authenticateUser(users, numUsers, username, password, "Admin")) {
                strcpy(buffer, "Admin login successful");
            } else {
                strcpy(buffer, "Admin login failed");
            }
        }
        else if (strcmp(role, "Student") == 0) {
            if (authenticateUser(users, numUsers, username, password, "Student")) {
                strcpy(buffer, "Student login successful");
            } else {
                strcpy(buffer, "Student login failed");
            }
        }
        else if (strcmp(role, "Faculty") == 0) {
            if (authenticateUser(users, numUsers, username, password, "Faculty")) {
                strcpy(buffer, "Faculty login successful");
            } else {
                strcpy(buffer, "Faculty login failed");
            }
            }
        else {
            strcpy(buffer, "Invalid role");
        }
}

int main(){

	//create socket
	struct sockaddr_in server, client;
	int servsd, newsd;//sock descriptor(server and new)
	char buf[1024];
	socklen_t addr_size;

	servsd = socket(AF_INET, SOCK_STREAM, 0); //inet: internet domain, sock stream: tcp, protocol 0
	if(servsd<0){ perror("Error in socket"); exit(1);}

	server.sin_family=AF_INET;
	server.sin_port=htons(3558);
	server.sin_addr.s_addr=INADDR_ANY; //inaddr_any: assigns ip adderss of current m/c automatically

	//bind socket
	if(bind(servsd, (struct sockaddr*) (&server), sizeof(server))<0){
		perror("error in binding");
		exit(1);
	}


	//listen
	if(listen(servsd,10)!=0){  //10=size of wait queue for connections
		perror("error in listening");
		exit(1);
	}

	//accept; concurrent server
	


	
	addr_size=sizeof(client);

	while(1){
	newsd=accept(servsd, (struct sockaddr*) (&client), &addr_size);
	if(newsd==-1){ 
		perror("error in accepting");
		close(servsd);
	}
	else{
		if(!fork()) { //only child enters this

			//user authentication
			login(newsd);
			close(newsd):
			exit(0)
		}
	
	}
	}

	close(servsd);
}


			




		
