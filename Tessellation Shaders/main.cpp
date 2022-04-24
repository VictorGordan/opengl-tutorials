#include"main.h"



int main()
{
	init();
	createContext();
	glEnableConfig();
	imGuiInit();
	initRender();


	glPatchParameteri(GL_PATCH_VERTICES, 4); // Quads
	//glPatchParameteri(GL_PATCH_VERTICES, 3); // Triangles

	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	while (!glfwWindowShouldClose(window))
	{
		displayStats();
		updateTimeDelta();
		glfwSetKeyCallback(window, key_callback);


		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		glClearColor(0.075f, 0.133f, 0.173f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		glUseProgram(shaderProgram);
		double cursorPos[2];
		glfwGetCursorPos(window, &cursorPos[0], &cursorPos[1]);
		glProgramUniform2f(shaderProgram, 0, float(cursorPos[0]) / SCREEN_WIDTH, 1.0 - float(cursorPos[1]) / SCREEN_HEIGHT);
		glBindVertexArray(VAO);
		if (wireframe)
		{
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			glDisable(GL_CULL_FACE);
		}
		else
		{
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glEnable(GL_CULL_FACE);
		}
		glDrawElements(GL_PATCHES, indices.size(), GL_UNSIGNED_INT, 0);

		ImGui::Begin("Tessellation");
		ImGui::Text("Press C to switch between rendering modes");
		ImGui::End();


		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(window);
		glfwPollEvents();
	}


	glfwDestroyWindow(window);
	glfwTerminate();
}