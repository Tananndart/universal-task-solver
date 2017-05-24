#pragma once

#ifdef UNIVERSALTASKSOLVER_EXPORTS
#define TASKSOLVER_API __declspec(dllexport) 
#else
#define TASKSOLVER_API __declspec(dllimport) 
#endif

#include <string>

namespace slv
{
	class TASKSOLVER_API ITask
	{
	public:
		virtual bool is_win() const = 0;

		virtual bool is_loose() const = 0;

		virtual void print_state(std::ostream& stream) const = 0;

		virtual int get_win_k() const = 0;

		virtual int get_command_count() const = 0;

		virtual std::string get_command_name(int id) const = 0;

		virtual void execute_command(int id) = 0;
	};

	class TASKSOLVER_API Solver
	{
	public:
		void execute(std::ostream& stream, ITask* game);
	};
}