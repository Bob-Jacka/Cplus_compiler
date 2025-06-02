/*
Abstract class for garbage collection process.
*/
class IGarbageCollector {

private:
	virtual void collectors_pass() const = 0;
	IGarbageCollector() = default;
public:
	virtual void collect_garbage() const = 0;
	virtual ~IGarbageCollector() = default;
};