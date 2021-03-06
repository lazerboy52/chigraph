/// \file chig/FunctionCompiler.hpp
/// Defines functions for compiling GraphFunction objects

#pragma once

#ifndef CHIG_FUNCTION_COMPILER_HPP
#define CHIG_FUNCTION_COMPILER_HPP

#include "chig/Fwd.hpp"
#include "chig/Result.hpp"

#include <llvm/IR/DIBuilder.h>
#include <llvm/IR/DebugInfo.h>
#include <llvm/IR/Module.h>

namespace chig {

/// Compile the graph to an \c llvm::Function (usually called from JsonModule::generateModule)
/// \param func The function to compile
/// \param mod The module to codgen into, should already be a valid module
/// \param debugCU The compilation unit that the GraphFunction resides in.
/// \param debugBuilder The debug builder to build debug info
/// \return The result
Result compileFunction(const GraphFunction& func, llvm::Module* mod, llvm::DICompileUnit* debugCU,
                       llvm::DIBuilder& debugBuilder);
}

#endif  // CHIG_FUNCTION_COMPILER_HPP
