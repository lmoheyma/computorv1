/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:24:38 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/06/01 20:37:24 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

double f(double x, t_coef coefs) {
    return (coefs.a * (x * x) + (coefs.b * x) + coefs.c);
}

static void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	(void)window;
    glViewport(0, 0, width, height);
}

static void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, 1);
}

int init_window(t_coef coefs) {
	if (!glfwInit()) {
    	fprintf(stderr, "Failed GLFW initialisation\n");
        return (1);
    }

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Function Plotter", NULL, NULL);
    if (window == NULL) {
        fprintf(stderr, "Failed window creation GLFW\n");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        fprintf(stderr, "Failed GLAD initialisation \n");
        return -1;
    }

    glViewport(0, 0, WIDTH, HEIGHT);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	
	while (!glfwWindowShouldClose(window)) {
        processInput(window);

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_LINES);
    		glVertex2f(-2 * M_PI, 0);
    		glVertex2f(2 * M_PI, 0);
			glVertex2f(0, -1.0);
    		glVertex2f(0, 1.0);
		glEnd();
		
		for (double x = -2 * M_PI; x <= 2 * M_PI; x+=M_PI / 3) {
			// printf("%.2f\n", x);
			glBegin(GL_LINES);
				glVertex2f((x - -2 * M_PI) / (2 * M_PI - -2 * M_PI) * 2 - 1, -0.02f);
            	glVertex2f((x - -2 * M_PI) / (2 * M_PI - -2 * M_PI) * 2 - 1, 0.02f);
			glEnd();
		}

		for (double y = -1.0; y <= 1.0; y += 0.2) {
			// printf("%.2f\n", x);
			glBegin(GL_LINES);
				glVertex2f(-0.02f, y);
				glVertex2f(0.02f, y);
			glEnd();
    	}
		
        glColor3f(1.0f, 0.0f, 0.0f);

        glBegin(GL_LINE_STRIP);
        for (double x = -2 * M_PI; x <= 2 * M_PI; x += 0.01) {
            double y = f(x, coefs);
            glVertex2f((x + 2 * M_PI) / (4 * M_PI) * 2 - 1, y);
        }
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();

	return (0);
}