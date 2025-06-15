/*
Abstract class for garbage collection process.
*/
class IGarbageCollector {

private:
	//One collector pass on objects alive
	virtual void collectors_pass() const = 0;

protected:
	IGarbageCollector() = default;

public:
	//Main function of collector
	virtual void collect_garbage() const = 0;
	virtual ~IGarbageCollector() = default;
};