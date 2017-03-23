#pragma once

#include <map>
#include <set>
#include <functional>

/*
Шаблонный интерфейс IObserver. Его должен реализовывать класс, 
желающий получать уведомления от соответствующего IObservable
Параметром шаблона является тип аргумента,
передаваемого Наблюдателю в метод Update
*/
template <typename T>
class IObserver
{
public:
	virtual void Update(T const& data) = 0;
	virtual ~IObserver() = default;
};

/*
Шаблонный интерфейс IObservable. Позволяет подписаться и отписаться на оповещения, а также
инициировать рассылку уведомлений зарегистрированным наблюдателям.
*/
template <typename T>
class IObservable
{
public:
	virtual ~IObservable() = default;
	virtual void RegisterObserver(IObserver<T> & observer, int priority) = 0;
	virtual void NotifyObservers() = 0;
	virtual void RemoveObserver(IObserver<T> & observer) = 0;
};

// Реализация интерфейса IObservable
template <class T>
class CObservable : public IObservable<T>
{
public:
	typedef IObserver<T> ObserverType;

	void RegisterObserver(ObserverType & observer, int priority) override
	{
		m_observers[priority].insert(&observer);
	}

	void NotifyObservers() override
	{
		ClearUnregisteredList();

		T data = GetChangedData();
		for (auto & it : m_observers)
		{
			for (auto observer : it.second)
			{
				observer->Update(data);
			}
		}
	}

	void RemoveObserver(ObserverType & observer) override
	{
		m_observersToDelete.insert(&observer);
	}

protected:
	// Классы-наследники должны перегрузить данный метод, 
	// в котором возвращать информацию об изменениях в объекте
	virtual T GetChangedData()const = 0;

private:
	std::map<int, std::set<ObserverType *>> m_observers;
	std::set<ObserverType *> m_observersToDelete;

	void ClearUnregisteredList()
	{
		for (auto observer : m_observersToDelete)
		{
			DeleteObserverFromList(*observer);
		}
		m_observersToDelete.clear();
	}

	void DeleteObserverFromList(ObserverType & observer)
	{
		for (auto & it : m_observers)
		{
			auto wantedObserver = it.second.find(&observer);
			if (wantedObserver != it.second.end())
			{
				it.second.erase(wantedObserver);
			}
		}
	}
};
