void QueueWithPriority::accelerate(){
	queue_iterator_type iter;
	queue_iterator_type first_iter;
	bool is_low = false;

	for(iter=--queue.end();; iter--){
		if(iter->priority == LOW){
			iter->priority = HIGH;
			first_iter = iter;
			is_low = true;
		}
		if(iter == queue.begin()){
			break;
		}
	}
	if(is_low){
		for(iter = queue.begin(); iter != queue.end(); iter++){
			if(iter->priority == NORMAL){
				queue.splice(iter, queue, first_iter, queue.end());
				break;
			}
		}
	}
}