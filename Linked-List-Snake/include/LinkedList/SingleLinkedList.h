#pragma once
#include <SFML/System/Vector2.hpp>
#include "LinkedList/Node.h"


namespace LinkedList
{
	enum class Operation
	{
		HEAD,
		MID,
		TAIL,
	};

	class SingleLinkedList
	{
	private:
		Node* head_node;

		float node_width;
		float node_height;

		sf::Vector2i default_position;
		Player::Direction default_direction;
		int linked_list_size;
		Node* createNode();
		int findMiddleNode();
	public:
		SingleLinkedList();
		~SingleLinkedList();

		void initialize(float width, float height, sf::Vector2i position, Player::Direction direction);
		void render();
		//void createHeadNode();

		sf::Vector2i getNewNodePosition(Node* reference_node);
		void updateNodePosition();
		void updateNodeDirection(Player::Direction direction_to_set);
		sf::Vector2i getNewNodePosition(Node* reference_node, Operation operation);
		void insertNodeAtTail();
		void insertNodeAtHead();
		void removeNodeAtHead();
		void removeNodeAtTail();
		void removeAllNodes();
		std::vector<sf::Vector2i> getNodesPositionList();
		bool processNodeCollision();
		Node* getHeadNode();
		void insertNodeAtMiddle();
		void shiftNodesAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node);
		void initializeNode(Node* new_node, Node* reference_node, Operation operation);

		void insertNodeAtIndex(int index);
	};
}


