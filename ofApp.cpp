#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetLineWidth(2);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	
	int len = 300;
	int size = 60;

	this->cam.begin();
	ofRotateX(ofGetFrameNum() * 0.37);
	ofRotateY(ofGetFrameNum() * 0.72);
	
	for (int s_1 = len * -0.5; s_1 <= len * 0.5; s_1 += size) {

		for (int s_2 = len * -0.5; s_2 <= len * 0.5; s_2 += size) {

			vector<glm::vec3> vertices;
			auto p = (len + size) * 0.5;

			vertices.clear();
			vertices.push_back(glm::vec3(p, s_1 - size * 0.5, s_2 - size * 0.5));
			vertices.push_back(glm::vec3(p, s_1 + size * 0.5, s_2 - size * 0.5));
			vertices.push_back(glm::vec3(p, s_1 + size * 0.5, s_2 + size * 0.5));
			vertices.push_back(glm::vec3(p, s_1 - size * 0.5, s_2 + size * 0.5));
			
			auto noise_value = ofNoise(p * 0.003, s_1 * 0.003, s_2 * 0.003, ofGetFrameNum() * 0.01);
			auto add = 0;
			if (noise_value > 0.65) {

				add = ofMap(noise_value, 0.65, 1, 0, size * 2);
			}
			for (auto& vertex : vertices) {

				vertex.x += add;
			}

			this->draw_panel(vertices);

			vertices.clear();
			vertices.push_back(glm::vec3(-p, s_1 - size * 0.5, s_2 - size * 0.5));
			vertices.push_back(glm::vec3(-p, s_1 + size * 0.5, s_2 - size * 0.5));
			vertices.push_back(glm::vec3(-p, s_1 + size * 0.5, s_2 + size * 0.5));
			vertices.push_back(glm::vec3(-p, s_1 - size * 0.5, s_2 + size * 0.5));

			noise_value = ofNoise(p * 0.003, s_1 * 0.003, s_2 * 0.003, ofGetFrameNum() * 0.01);
			add = 0;
			if (noise_value > 0.65) {

				add = ofMap(noise_value, 0.65, 1, 0, size * 2);
			}
			for (auto& vertex : vertices) {

				vertex.x -= add;
			}

			this->draw_panel(vertices);

			vertices.clear();
			vertices.push_back(glm::vec3(s_1 - size * 0.5, p, s_2 - size * 0.5));
			vertices.push_back(glm::vec3(s_1 + size * 0.5, p, s_2 - size * 0.5));
			vertices.push_back(glm::vec3(s_1 + size * 0.5, p, s_2 + size * 0.5));
			vertices.push_back(glm::vec3(s_1 - size * 0.5, p, s_2 + size * 0.5));

			noise_value = ofNoise(s_1 * 0.003, p * 0.003, s_2 * 0.003, ofGetFrameNum() * 0.01);
			add = 0;
			if (noise_value > 0.65) {

				add = ofMap(noise_value, 0.65, 1, 0, size * 2);
			}
			for (auto& vertex : vertices) {

				vertex.y += add;
			}

			this->draw_panel(vertices);

			vertices.clear();
			vertices.push_back(glm::vec3(s_1 - size * 0.5, -p, s_2 - size * 0.5));
			vertices.push_back(glm::vec3(s_1 + size * 0.5, -p, s_2 - size * 0.5));
			vertices.push_back(glm::vec3(s_1 + size * 0.5, -p, s_2 + size * 0.5));
			vertices.push_back(glm::vec3(s_1 - size * 0.5, -p, s_2 + size * 0.5));

			noise_value = ofNoise(s_1 * 0.003, p * 0.003, s_2 * 0.003, ofGetFrameNum() * 0.01);
			add = 0;
			if (noise_value > 0.65) {

				add = ofMap(noise_value, 0.65, 1, 0, size * 2);
			}
			for (auto& vertex : vertices) {

				vertex.y -= add;
			}

			this->draw_panel(vertices);

			vertices.clear();
			vertices.push_back(glm::vec3(s_1 - size * 0.5, s_2 - size * 0.5, p));
			vertices.push_back(glm::vec3(s_1 + size * 0.5, s_2 - size * 0.5, p));
			vertices.push_back(glm::vec3(s_1 + size * 0.5, s_2 + size * 0.5, p));
			vertices.push_back(glm::vec3(s_1 - size * 0.5, s_2 + size * 0.5, p));

			noise_value = ofNoise(s_1 * 0.003, s_2* 0.003, p * 0.003, ofGetFrameNum() * 0.01);
			add = 0;
			if (noise_value > 0.65) {

				add = ofMap(noise_value, 0.65, 1, 0, size * 2);
			}
			for (auto& vertex : vertices) {

				vertex.z += add;
			}

			this->draw_panel(vertices);

			vertices.clear();
			vertices.push_back(glm::vec3(s_1 - size * 0.5, s_2 - size * 0.5, -p));
			vertices.push_back(glm::vec3(s_1 + size * 0.5, s_2 - size * 0.5, -p));
			vertices.push_back(glm::vec3(s_1 + size * 0.5, s_2 + size * 0.5, -p));
			vertices.push_back(glm::vec3(s_1 - size * 0.5, s_2 + size * 0.5, -p));

			noise_value = ofNoise(s_1 * 0.003, s_2 * 0.003, p * 0.003, ofGetFrameNum() * 0.01);
			add = 0;
			if (noise_value > 0.65) {

				add = ofMap(noise_value, 0.65, 1, 0, size * 2);
			}
			for (auto& vertex : vertices) {

				vertex.z -= add;
			}

			this->draw_panel(vertices);
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
void ofApp::draw_panel(vector<glm::vec3> vertices) {

	ofMesh face, line;
	face.addVertices(vertices);

	face.addIndex(0); face.addIndex(1); face.addIndex(2);
	face.addIndex(0); face.addIndex(2); face.addIndex(3);

	ofSetColor(239);
	face.draw();

	line.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);
	line.addVertices(vertices);

	line.addIndex(0); line.addIndex(1);
	line.addIndex(1); line.addIndex(2);
	line.addIndex(2); line.addIndex(3);
	line.addIndex(3); line.addIndex(0);

	ofSetColor(39);
	line.drawWireframe();
}

//--------------------------------------------------------------
glm::vec2 ofApp::make_point(int len, int param) {

	param = param % 100;
	if (param < 25) {

		return glm::vec2(ofMap(param, 0, 25, -len * 0.5, len * 0.5), -len * 0.5);
	}
	else if (param < 50) {

		return glm::vec2(len * 0.5, ofMap(param, 25, 50, -len * 0.5, len * 0.5));
	}
	else if (param < 75) {

		return glm::vec2(ofMap(param, 50, 75, len * 0.5, -len * 0.5), len * 0.5);
	}
	else {

		return glm::vec2(-len * 0.5, ofMap(param, 75, 100, len * 0.5, -len * 0.5));
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}