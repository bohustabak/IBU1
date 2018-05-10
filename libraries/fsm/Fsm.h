// This file is part of arduino-fsm.
//
// arduino-fsm is free software: you can redistribute it and/or modify it under
// the terms of the GNU Lesser General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option)
// any later version.
//
// arduino-fsm is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License
// for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with arduino-fsm.  If not, see <http://www.gnu.org/licenses/>.

#ifndef FSM_H
#define FSM_H


#if defined(ARDUINO) && ARDUINO >= 100
  #include <Arduino.h>
#else
  #include <WProgram.h>
#endif


struct State{
  State(void (*on_enter)(), void (*on_state)(), void (*on_exit)());
  void (*on_enter)();
  void (*on_state)();
  void (*on_exit)();
};

class Fsm{
    public:
    int state;
    void trigger(int state){ 
        this->state = state;
    }
    
};
template<typename T> // type with alias T
struct Reference{ //compiletime reference wraper simmilar to std::reference
    T& ref; //reference
    constexpr Reference(T& reference) : ref(reference){}
};

class Fsm{
	public:
		Fsm(State* initial_state);
		~Fsm();

		void add_transition(State* state_from, State* state_to, int event, void (*on_transition)());
		void add_timed_transition(State* state_from, State* state_to, unsigned long interval, void (*on_transition)());
		void check_timed_transitions();
		void trigger(int event);
		void run_machine();

	private:
		struct Transition{
			State* state_from;
			State* state_to;
			int event;
			void (*on_transition)();
		};
		struct TimedTransition{
			Transition transition;
			unsigned long start;
			unsigned long interval;
  		};

	static Transition create_transition(State* state_from, State* state_to, int event, void (*on_transition)());
  	void make_transition(Transition* transition);

	private:
	  State* m_current_state;
	  Transition* m_transitions;
	  int m_num_transitions;

	  TimedTransition* m_timed_transitions;
	  int m_num_timed_transitions;
	  bool m_initialized;
};


struct Flat{
    //initiliazer_list is language level class that can store any number of elements of the same type
    const std::initializer_list< Reference<Fsm> > list; //Fsm* could be used instead of Reference<Fsm> but you would need to write & when passing the elements {&st1,&st2,&st3}
    public:
    
    //const expressed constructor that will be called in compiletime
    constexpr Flat(const std::initializer_list< Reference<Fsm> > l) : list(l){}

    void trigger(int state){
        
        for(auto& it : list){//range based for loop added in C++11 google it
            it.ref.trigger(state); 
        }
    }
};




#endif
