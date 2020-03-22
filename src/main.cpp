/*********************************************************************
 * Módulo 2. Curso de Experto en Desarrollo de Videojuegos
 * Autor: Carlos González Morcillo     Carlos.Gonzalez@uclm.es
 *
 * You can redistribute and/or modify this file under the terms of the
 * GNU General Public License ad published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * and later version. See <http://www.gnu.org/licenses/>.
 *
 * This file is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.  
 *********************************************************************/

#include "ExampleApplication.h"
#include <iostream>

class SimpleExample : public ExampleApplication {
  public :
	void createScene() {
		Ogre::Entity *ent = mSceneMgr->createEntity("MyEntity", "Sinbad.mesh");
		mSceneMgr->setAmbientLight(Ogre::ColourValue(1, 1, 1));
		Ogre::SceneNode* node = mSceneMgr->createSceneNode("Node1");
		node->setPosition(10,10,0);
		mSceneMgr->getRootSceneNode()->addChild(node);
		node->attachObject(ent);

		Ogre::Entity *ent2 = mSceneMgr->createEntity("MyEntity2", "Sinbad.mesh");
		Ogre::SceneNode* node2 = node->createChildSceneNode("node2");
		node2->setPosition(10,0,0);
		node2->scale(2.0f, 2.0f, 2.0f);
		node2->attachObject(ent2);
		std::cout << "Posición Nodo 2:" << node2->_getDerivedPosition() << std::endl;


		Ogre::Entity* ent3 = mSceneMgr->createEntity("MyEntity3", "Sinbad.mesh");
		Ogre::SceneNode* node3 = node->createChildSceneNode("node3", Ogre::Vector3(20,0,0));
		node3->scale(0.2f, 0.2f, 0.2f);
		node3->attachObject(ent3);
		std::cout << "Posición Nodo 3:" << node3->_getDerivedPosition() << std::endl;
  }
};

int main(void) {
  SimpleExample example;
  example.go();
  
  return 0;
}
