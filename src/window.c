/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:24:38 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/06/01 17:18:13 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"
#include <math.h>

double f(double x) {
    return sin(x);
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
	(void)coefs;
	if (!glfwInit()) {
    	fprintf(stderr, "Failed GLFW initialisation\n");
        return (1);
    }

	// glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    // glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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
        // Traitement des entrées
        processInput(window);

        // Effacement de l'écran
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Définir la couleur de la courbe (blanc)
        glColor3f(1.0f, 1.0f, 1.0f);

        // Tracer la courbe
        glBegin(GL_LINE_STRIP);
        for (double x = -2 * M_PI; x <= 2 * M_PI; x += 0.01) {
            double y = f(x);
            glVertex2f((x + 2 * M_PI) / (4 * M_PI) * 2 - 1, y);
        }
        glEnd();

        // Échange des tampons et vérification des événements
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Nettoyage et fermeture
    glfwTerminate();

	return (0);
}