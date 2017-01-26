/**
 * Least Recently Used Cache
 * \file lru_cache.h
 * \author KDuncan
 */
#pragma once
#ifndef KD_LRU_CACHE_H_
#define KD_LRU_CACHE_H_

#include <map>
#include <vector>

/*
 * To get around error C3646 in Visual Studio because of noexcept
 */
#ifndef _MSC_VER
#	define NOEXCEPT noexcept
#else
#	define NOEXCEPT
#endif

namespace kd
{
    /**
     * \brief Least Recently Used Cache
     *
     * This class implements a solution for the following problem:
     *
     * Implement a least recently used (LRU) cache that has constant access
     * for all operations. This is done using a combination of a hash map
     * and doubly-linked list nodes.
     */
    template <typename KeyType, typename ValueType>
    class LRUCache
    {
    public:

        /**
         * \brief Constructor
         * \param capacity The max number of cache elements (default: 100)
         */
        LRUCache(size_t capacity = 100)
            : mCapacity(capacity), mHead(nullptr), mTail(nullptr), mEntries()
        {

        }

        /**
         * \brief Destructor
         */
        virtual ~LRUCache()
        {
            for (auto elem : this->mEntries)
            {
                if (elem.second)
                {
                    delete elem.second;
                    elem.second = nullptr;
                }
            }
            this->mEntries.clear();
        }

        /**
         * Adds an element to the cache
         * \param key Key to use for identifying entry
         * \param value Value of the entry
         */
        void add(const KeyType& key, const ValueType& value)
        {
            try
            {
                EntryNode* elem(nullptr);

                if (!this->hasEntry(key, &elem))
                {
                    elem = new EntryNode(key, value);
                    if (this->mEntries.size() == this->mCapacity)
                    {
                        auto elemToDelete = this->mEntries.find(this->mTail->key);
                        this->mEntries.erase(this->mTail->key);
                        this->mTail = this->mTail->prev;
                        
                        if (this->mTail != nullptr)
                        {
                            this->mTail->next = nullptr;
                        }
                        
                        if (elemToDelete != this->mEntries.end())
                        {
                            delete elemToDelete->second;
                        }                        
                    }
                    this->mEntries[key] = elem;
                }

                elem->value = value;
                this->moveToHead(&elem);

                if (this->mTail == nullptr)
                {
                    this->mTail = this->mHead;
                }
            }
            catch (const std::exception &ex)
            {
                printf("%s --> An unexpected error has occurred: %s\n", __FUNCTION__, ex.what());
            }
            catch (...)
            {
                printf("%s --> Unexpected error occurred\n", __FUNCTION__);
            }
        }

        /**
         * Adds an element to the cache
         * \param key Key to use for identifying entry
         * \param value Value of the entry
         */
        inline ValueType& operator[] (const KeyType& key)
        {
            EntryNode* elem(nullptr);
            while (!this->hasEntry(key, &elem))
            {
                this->add(key, ValueType());
            }
            return elem->value;
        }

        /**
         * Adds an element to the cache
         * \param key Key to use for identifying entry
         * \param value Value of the entry
         */
        inline const ValueType& operator[] (const KeyType& key) const
        {
            EntryNode* elem(nullptr);
            while (!this->hasEntry(key, &elem))
            {
                this->add(key, ValueType());
            }
            return elem->value;
        }

        /**
         * \brief Get the current size of the cache
         */
		inline size_t size() const NOEXCEPT
        {
            return this->mEntries.size();
        }

        /**
         * \brief Get the values of this cache as a vector
         * \return A vector of type ValueType
         */
        inline std::vector<std::pair<KeyType, ValueType>> toVector() const
        {
            std::vector<std::pair<KeyType, ValueType>> vec;
            vec.reserve(this->mEntries.size());

            for (auto it = this->mEntries.begin(); it != this->mEntries.end(); ++it)
            {
                auto k = it->first;
                auto v = it->second->value;
                vec.push_back(std::pair<KeyType, ValueType>(k, v));
            }

            return std::move(vec);
        }


    protected:
        /**
         * \brief Doubly-linked node to facilitate constant access
         */
        struct EntryNode
        {
			EntryNode() NOEXCEPT
                : key(), value(), prev(nullptr), next(nullptr)
            {

            }
			EntryNode(const KeyType& key_, const ValueType& value_) NOEXCEPT
                : key(key_), value(value_), prev(nullptr), next(nullptr)
            {

            }

            KeyType key;
            ValueType value;
            EntryNode* prev;
            EntryNode* next;
        };

        /**
         * \brief Checks to see if the entry is in the cache
         * \param key Key used to identify entry
         * \param entry The element identified by the key
         * \return true if the entry is already in the cache
         */
        bool hasEntry(const KeyType& key, EntryNode** entry) const
        {
            try
            {
                auto elemIter = this->mEntries.find(key);
                if (entry != nullptr && elemIter != this->mEntries.end())
                {
                    *entry = elemIter->second;
                    return true;
                }
                return false;
            }
            catch (...)
            {
                return false;
            }
        }

        /**
         * \brief Moves a recently used element to the head of the list
         * \param elem The element
         */
        void moveToHead(EntryNode** elem)
        {
            try
            {
                if (elem == nullptr ||
                   (elem != nullptr && *elem == nullptr) ||
                   (elem != nullptr && *elem == this->mHead))
                {
                    return;
                }

                EntryNode* next = (*elem)->next;
                EntryNode* prev = (*elem)->prev;

                if (next != nullptr)
                {
                    next->prev = (*elem)->prev;
                }

                if (prev != nullptr)
                {
                    prev->next = (*elem)->next;
                }

                (*elem)->prev = nullptr;
                (*elem)->next = this->mHead;

                if (this->mHead != nullptr)
                {
                    this->mHead->prev = *elem;
                }
                this->mHead = *elem;

                if (this->mTail == *elem)
                {
                    this->mTail = prev;
                }
            }
            catch (const std::exception& ex)
            {
                printf("%s --> An unexpected error occurred: %s\n", __FUNCTION__, ex.what());
            }
        }

        /// Disable copying semantics
        LRUCache(const LRUCache&) = delete;
        LRUCache(const LRUCache&&) = delete;
        LRUCache& operator= (const LRUCache&) = delete;
        LRUCache& operator= (const LRUCache&&) = delete;


    protected:
        /**
         * \brief Maximum number of elements in the cache
         */
        size_t mCapacity;

        /**
         * \brief Pointer to the most recently used entry
         */
        EntryNode* mHead;

        /**
         * \brief Pointer to the least recently used entry
         */
        EntryNode* mTail;

        /**
         * \brief Hashmap to store the entries to facilitate O(1) access
         */
        std::map<KeyType, EntryNode*> mEntries;
    };


    /**
     * Function to test the above implementation of an LRU Cache
     */
    void testLRUCache();

} // namespace kd

#endif /* KD_LRU_CACHE_H_ */
