package com.techburg.autospring.custombean;

import org.springframework.beans.BeansException;
import org.springframework.beans.factory.config.BeanPostProcessor;

import com.techburg.autospring.task.abstr.IBuildTaskProcessor;

public class TaskProcessorAutoStart implements BeanPostProcessor {

	@Override
	public Object postProcessAfterInitialization(Object bean, String beanName)
			throws BeansException {
		return bean;
	}

	@Override
	public Object postProcessBeforeInitialization(Object bean, String beanName)
			throws BeansException {
		if(beanName.equals("buildTaskProcessor")) {
			((IBuildTaskProcessor)bean).start();
		}
		return bean;
	}

}
