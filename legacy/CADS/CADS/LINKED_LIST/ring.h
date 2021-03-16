#pragma once

namespace CADS
{
	template <typename _TYPE>
	class NodeBase {
		_TYPE = node_data;
		NodeBase* next;
		NodeBase* previous;
	public:
		NodeBase() :node_data(), next(nullptr), previous(nullptr) {}
		NodeBase() {}
		~NodeBase() {}
	};

	template<typename _TYPE, typename size_t _SIZE>
	class Ring {

	};
}


